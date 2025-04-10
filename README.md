# Visual-NanoPore
## qt c++ software for nanopore data visualize and analysis. 
this software might be fully released after my papers are published. QAQ  
I wrote in here is for postdoc or job application.  
this software only focuse on peak detection and visualize, then running speed priority.   
The post analysis can easily handled in python script by using the time-tag of the events.   
![image](https://github.com/user-attachments/assets/04b24eb6-fd67-4fd1-9a03-50379bfc5293)
## visualization algorithm
This software uses data pyramid to accelerate the data plotting, so its fast and can handle large dataset (2^32 bytes points). 
## peak find manually
![image](https://github.com/user-attachments/assets/993731c3-21c2-4262-a3fb-b721c1ed055e)
1. we can easily add the events by drag the bar
![image](https://github.com/user-attachments/assets/21559758-1168-4648-a5d7-9cbd1050e570)
2. fist / second button will add / remove the events to the list (a temperary list is maintained for the detected events), third and fourth will add / remove from the storage file 
![image](https://github.com/user-attachments/assets/61cb502a-e606-40d0-a86d-e37c172ce90d)
it becoomes green when the detected points was saved in csv file
![image](https://github.com/user-attachments/assets/bab43e5a-736a-40cc-b3fe-bc53d602d08b)
3. the red events can add/remove to temporary or storage events list. the algorithm will merge them automatically, and here is the rules for add.
*1221 -> 22; 1122 -> 1122; 1212 -> 22; 2121 - > 22; 2211 -> 2211*
## peak find auto
1. I use a real-time algorithm to extract the peaks, which is O(n) or O(nlogk, if you choice the median values as baseline)
the detection approach uses moving std, mean, median to detect the start point of events, and use z-test to get end points. almost same performance with moving baseline approach(Ana Chem 2009), but faster and more reliable for long events.
2. the events detection will not block the main UI, the processes will be shown in the green/red process bar on the top.
## peak find auto-manually 
![image](https://github.com/user-attachments/assets/b8da1172-2499-42ad-bac8-3a9d7b60fc0b)
1. we can choose the data analysis region we are interested.
## run batch
if you open the multiple files in the files directory， then the rocket button will anlysis all of them without block. we need double click the file to replot it after finishing. 
## calculate the shape and volume of proteins
1. setting the parameters in the gear
![image](https://github.com/user-attachments/assets/3d2f9934-e503-4186-acc3-34c3f73897c3)
2. double click the events will see the message box about protiens estimation
3.  




test on 1.8Ghz cpu, single threads could process the data with a ~2000 Mb/s speed.
provide a manual events correction, and vis.

