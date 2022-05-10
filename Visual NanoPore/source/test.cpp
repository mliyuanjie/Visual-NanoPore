// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <ws2tcpip.h>
#include <windows.h>
#include <netioapi.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/json.hpp>
#include "json.hpp"


#pragma comment(lib, "iphlpapi.lib")

bool getDevices(std::vector<MIB_IF_ROW2>& vetIFRow)
{
    PMIB_IF_TABLE2 table = NULL;
    if (GetIfTable2Ex(MibIfTableRaw, &table) != NOERROR || !table)
    {
        return false;
    }

    for (ULONG i = 0; i < table->NumEntries; i++)
    {
        MIB_IF_ROW2 row;
        ZeroMemory(&row, sizeof(MIB_IF_ROW2));
        row.InterfaceIndex = i;
        if (GetIfEntry2(&row) == NOERROR)
        {
            vetIFRow.push_back(row);
        }
    }

    FreeMibTable(table);
    return true;
}

BOOL isNetIFConnected(const MIB_IF_ROW2& row)
{
    return (row.TunnelType == TUNNEL_TYPE_NONE &&
        row.AccessType != NET_IF_ACCESS_LOOPBACK &&
        row.InterfaceAndOperStatusFlags.HardwareInterface == TRUE &&
        row.MediaConnectState == MediaConnectStateConnected);
}

void getNetMac(char* res)
{
    std::vector<MIB_IF_ROW2> vectRow;
    bool bRet = getDevices(vectRow); // ETHERNET adapters
    if (bRet)
    {
        for (int i = 0; i < vectRow.size(); i++)
        {
            if (isNetIFConnected(vectRow[i]))
            {
                unsigned long size = vectRow[i].PhysicalAddressLength;
                char* p = res;
                for (unsigned long j = 0; j < size; j++) {
                    snprintf(p, 3, "%x.2x", vectRow[i].PhysicalAddress[j]);
                    p += 2;
                }
                return;
            }
        }
    }
    vectRow.clear();
    return;
}

std::string login(std::string host, int port, std::string name, std::string pwd)
{
    char macaddress[] = "aaaaaaaaaaaa";
    getNetMac(macaddress);

    boost::asio::io_service ios;

    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(host), port);

    boost::asio::ip::tcp::socket socket(ios);

    socket.connect(endpoint);


    boost::json::object message;
    message["name"] = name.c_str();
    message["pwd"] = pwd.c_str();
    message["macaddress"] = macaddress;


    boost::system::error_code error;
    std::string mess = boost::json::serialize(message);
    socket.write_some(boost::asio::buffer(mess), error);
    char res[50];
    int size = socket.read_some(boost::asio::buffer(res), error);
    socket.close();

    return std::string(res, size);
}

std::string logon(std::string host, int port, std::string name, std::string pwd) {
    char macaddress[] = "aaaaaaaaaaaa";
    getNetMac(macaddress);

    boost::asio::io_service ios;

    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(host), port);

    boost::asio::ip::tcp::socket socket(ios);

    socket.connect(endpoint);


    boost::json::object message;
    message["name"] = name.c_str();
    message["pwd"] = pwd.c_str();
    message["macaddress"] = macaddress;
    message["securitykey"] = "ahsdfhs";


    boost::system::error_code error;
    std::string mess = boost::json::serialize(message);
    socket.write_some(boost::asio::buffer(mess), error);
    char res[50];
    int size = socket.read_some(boost::asio::buffer(res), error);
    socket.close();

    return std::string(res, size);
}

int main() {
    std::string b = logon("115.159.22.158", 8088, "lyj", "664765%");
    std::string a = login("115.159.22.158", 8087, "lyj", "664765%");
    
    return 0;
}