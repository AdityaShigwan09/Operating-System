# Write a python program to Display column-wise mean, and median for SOCR- HeightWeight dataset.


import pandas as pd
import numpy as np


url = "data2.csv"
df = pd.read_csv(url)

df = df.iloc[1:]

df = df.apply(pd.to_numeric, errors='coerce')


column_means = df.mean()

column_medians = df.median()


print("Column-wise Mean:")
print(column_means)
print("\nColumn-wise Median:")
print(column_medians)