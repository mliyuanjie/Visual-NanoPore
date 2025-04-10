# Visual-NanoPore
a qt c++ software for nanopore data visualize and analysis. 
![image](https://github.com/user-attachments/assets/04b24eb6-fd67-4fd1-9a03-50379bfc5293)

This software uses data pyramid to accelerate the data plotting, so its fast and can handle large dataset (2^32 bytes points)

provide a real-time analysis for the data with a high speed, based on two statistic sliding window. test on 1.8Ghz cpu, single threads could process the data with a ~2000 Mb/s speed. the algorithm O(N).
provide a manual events correction, and vis.

