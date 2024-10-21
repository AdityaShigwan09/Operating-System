# Q.2 B) Write a Python program to view basic statistical details of the data (Use Heights and Weights Dataset)

import pandas as pd
import numpy as np


df = pd.read_csv('data.csv')


print("Dataset Information:")
print(df.info())
print("\n")


print("First few rows of the dataset:")
print(df.head())
print("\n")


print("Basic Statistical Details:")
print(df.describe())
print("\n")


print("Additional Statistics:")
print("Median:")
print(df.median())
print("\nMode:")
print(df.mode().iloc[0])  
print("\nSkewness:")
print(df.skew())
print("\nKurtosis:")
print(df.kurtosis())


if len(df.columns) > 1:
    print("\nCorrelation Matrix:")
    print(df.corr())