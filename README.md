# Parallel kmeans algorithm

This repository has a data folder which contains all the data we tested our serial and parallel implementations on

An src folder which contains a folder with parallel and sequential kmeans, which in turn contain all the kmeans code.





# Report

We in the end could not get ying-yang kmeans and the scallable kmeans++ initializations to work given the complexity of the code and no implementations in C++ online. Our attempts to implement the two algorithms are documented in the ying_yang_try folder and the initializations/parallel/ folder. We will get back to this code over the summer and make a full video on the different implementations of kmeans and running tests in parallel. Goal is to have a video out by September.

On the results portion we ran the speed and accuracy results on generated datasets from generate_data.py. We report the results on different hyperparameters. We ran tests on a llyods algorithm, kmeans++, parallel lloyds, and parallel assignment and kmeans++ initialization. Note that our code makes it easy (in theory) do update the different update, assignment, initialization steps and test out various implementations of these methods and can help make a general kmeans repository. Now we report the results:

For n = 100000000, d = 2, k = 100 (size of data csv 3.5GB) generated data we had the following

Time (seconds) for k = 10, max_iterations = 1000:
Lloyds : 212.363
KMeansPlusPlus : 315.233
LloydParallelKMeans : 74.8186
KmeansPlusPlusParallel : 107.084

Accuracy for k = 10, max_iterations = 1000:
Lloyds : 6.14954e+08
KMeansPlusPlus : 6.08418e+08
LloydParallelKMeans : 6.08418e+08
KmeansPlusPlusParallel : 6.08418e+08


Time (seconds) for k = 3, max_iterations = 1000:
Lloyds : 80.1984
KMeansPlusPlus : 39.2795
LloydParallelKMeans : 39.7117
KmeansPlusPlusParallel : 30.3844

Accuracy for k = 3, max_iterations = 1000:
Lloyds : 2.47377e+09
KMeansPlusPlus :  2.47377e+09
LloydParallelKMeans : 2.47377e+09
KmeansPlusPlusParallel : 2.47377e+09


For n = 10000000, d = 25, k = 3 (size of data csv 4.38GB) generated data we had the following


Time (seconds) for k = 3, max_iterations = 1000:
Lloyds : 3.31376
KMeansPlusPlus : 3.03789
LloydParallelKMeans : 1.28703
KmeansPlusPlusParallel : 2.51896

Accuracy for k = 3, max_iterations = 1000:
Lloyds :  2.50055e+08
KMeansPlusPlus :  2.50055e+08
LloydParallelKMeans : 2.50055e+08
KmeansPlusPlusParallel : 2.50055e+08

For n = 1000000, d = 25, k = 3 (size of data csv 448.3MB) generated data we had 

Time (seconds) for k = 50, max_iterations = 1000:
Lloyds : 746.61
KMeansPlusPlus : 751.107
LloydParallelKMeans : 108.717
KmeansPlusPlusParallel :141.625

Accuracy for k = 50, max_iterations = 1000:
Lloyds :  2.15637e+07
KMeansPlusPlus :  2.15635e+07
LloydParallelKMeans : 2.1612e+07
KmeansPlusPlusParallel : 2.15535e+07



Time (seconds) for k = 10, max_iterations = 1000:
Lloyds : 171.264
KMeansPlusPlus : 172.993
LloydParallelKMeans : 37.0919
KmeansPlusPlusParallel : 42.6006

Accuracy for k = 10, max_iterations = 1000:
Lloyds :   2.4132e+07
KMeansPlusPlus :  2.38281e+07
LloydParallelKMeans : 2.41582e+07
KmeansPlusPlusParallel : 2.3847e+07



For n = 100000, d = 100, k = 3 (size of data csv 179MB) generated data we had
 

Time (seconds) for k = 3, max_iterations = 1000:
Lloyds : 5.05861
KMeansPlusPlus : 21.4701
LloydParallelKMeans : 0.04095
KmeansPlusPlusParallel : 0.036461

Accuracy for k = 3, max_iterations = 1000:
Lloyds :   1.31051e+08
KMeansPlusPlus :  1.29545e+08
LloydParallelKMeans : 9.99989e+06
KmeansPlusPlusParallel : 9.99989e+06



Time (seconds) for k = 10, max_iterations = 1000:
Lloyds : 19.0687
KMeansPlusPlus : 11.4842
LloydParallelKMeans : 4.38662
KmeansPlusPlusParallel : 3.79405

Accuracy for k = 10, max_iterations = 1000:
Lloyds :  9.8828e+06
KMeansPlusPlus :  9.8671e+06
LloydParallelKMeans : 9.86993e+06
KmeansPlusPlusParallel : 9.86966e+06


Time (seconds) for k = 100, max_iterations = 1000:
Lloyds : 106.42
KMeansPlusPlus :  81.9319
LloydParallelKMeans : 16.3299
KmeansPlusPlusParallel :  44.2093

Accuracy for k = 100, max_iterations = 1000:
Lloyds :  9.46957e+06
KMeansPlusPlus :  9.46993e+06
LloydParallelKMeans : 9.47e+06
KmeansPlusPlusParallel : 9.47054e+06



Time (seconds) for k = 300, max_iterations = 1000:
Lloyds : 165.05
KMeansPlusPlus : 336.268 
LloydParallelKMeans : 12.6247
KmeansPlusPlusParallel :  250.992

Accuracy for k = 300, max_iterations = 1000:
Lloyds :  9.21644e+06
KMeansPlusPlus :  9.2182e+06
LloydParallelKMeans :  9.22255e+06
KmeansPlusPlusParallel : 9.2203e+0





For n = 100000, d = 100, k = 100 (size of data csv 179.50MB) generated data we had
 

Time (seconds) for k = 300, max_iterations = 1000:
Lloyds: 1176.77
KMeansPlusPlus: 211.49
LloydParallelKMeans: 163.423
KmeansPlusPlusParallel: 242.215

Accuracy for k = 300, max_iterations = 1000:
Lloyds: 9.82159e+06
KMeansPlusPlus: 9.81784e+06
LloydParallelKMeans: 9.82924e+06
KmeansPlusPlusParallel: 9.81565e+06


Time (seconds) for k = 100, max_iterations = 1000:
Lloyds: 395.657
KMeansPlusPlus: 31.7592
LloydParallelKMeans: 58.1253
KmeansPlusPlusParallel: 28.5216

Accuracy for k = 100, max_iterations = 1000:
Lloyds: 7.60786e+07
KMeansPlusPlus: 2.50744e+07
LloydParallelKMeans: 6.89111e+07
KmeansPlusPlusParallel: 2.48369e+07


Time (seconds) for k = 30, max_iterations = 1000:
Lloyds: 112.001
KMeansPlusPlus: 2.06098
LloydParallelKMeans: 21.3771
KmeansPlusPlusParallel: 2.38521

Accuracy for k = 30, max_iterations = 1000:
Lloyds: 2.17423e+08
KMeansPlusPlus: 2.1173e+08
LloydParallelKMeans: 2.19696e+08
KmeansPlusPlusParallel: 2.12597e+08

Time (seconds) for k = 10, max_iterations = 1000:
Lloyds: 0.564978
KMeansPlusPlus: 0.609305
LloydParallelKMeans: 0.091643
KmeansPlusPlusParallel: 0.333204

Accuracy for k = 10, max_iterations = 1000:
Lloyds: 2.9176e+08
KMeansPlusPlus: 2.89653e+08
LloydParallelKMeans: 2.89946e+08
KmeansPlusPlusParallel: 2.90826e+08





