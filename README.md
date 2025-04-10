# Visual-NanoPore
## qt c++ software for nanopore data visualize and analysis. 
this software might be fully released after my paper was published. QAQ
I wrote in here is for postdoc or job application
![image](https://github.com/user-attachments/assets/04b24eb6-fd67-4fd1-9a03-50379bfc5293)
## visualization algorithm
This software uses data pyramid to accelerate the data plotting, so its fast and can handle large dataset (2^32 bytes points). 
## peak find manually
![image](https://github.com/user-attachments/assets/993731c3-21c2-4262-a3fb-b721c1ed055e)
1. we can easily add the events by drag the bar
2. fist button will add the events to the list (a temperary list is maintained for the detected events)
3. ![image](https://github.com/user-attachments/assets/21559758-1168-4648-a5d7-9cbd1050e570)


provide a real-time analysis for the data with a high speed, based on two statistic sliding window. test on 1.8Ghz cpu, single threads could process the data with a ~2000 Mb/s speed. the algorithm O(N).
provide a manual events correction, and vis.

