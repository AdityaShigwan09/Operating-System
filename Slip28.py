# Q.2) Write a Python program [15]
# 1. To create a dataframe containing columns name, age and percentage. Add 10 rows to the dataframe. View the dataframe.
# 2. To print the shape, number of rows-columns, data types, feature names and the description of the data.
# 3. To view basic statistical details of the data.
# 4. To Add 5 rows with duplicate values and missing values. Add a column „remarks‟ with empty values. Display the data.



import pandas as pd
import numpy as np

# 1. Create a dataframe with 10 rows
data = {
    'name': ['Alice', 'Bob', 'Charlie', 'David', 'Eva', 'Frank', 'Grace', 'Henry', 'Ivy', 'Jack'],
    'age': [25, 30, 35, 28, 22, 40, 33, 45, 27, 31],
    'percentage': [85.5, 92.0, 78.3, 88.7, 95.2, 82.1, 90.6, 76.9, 93.8, 87.4]
}

df = pd.DataFrame(data)

# View the dataframe
print("1. Dataframe:")
print(df)
print("\n")

# 2. Print shape, number of rows-columns, data types, feature names, and description
print("2. Dataframe Information:")
print(f"Shape: {df.shape}")
print(f"Number of rows: {df.shape[0]}")
print(f"Number of columns: {df.shape[1]}")
print("\nData Types:")
print(df.dtypes)
print("\nFeature Names:")
print(df.columns)
print("\nDescription:")
print(df.describe())
print("\n")

# 3. View basic statistical details
print("3. Basic Statistical Details:")
print(df.describe())
print("\n")

# 4. Add 5 rows with duplicate and missing values, and a 'remarks' column
new_data = {
    'name': ['Alice', 'Bob', np.nan, 'David', 'Eva'],
    'age': [25, 30, 35, np.nan, 22],
    'percentage': [85.5, 92.0, np.nan, 88.7, 95.2],
    'remarks': ['', '', '', '', '']
}

df_new = pd.DataFrame(new_data)
df = pd.concat([df, df_new], ignore_index=True)

# Display the updated dataframe
print("4. Updated Dataframe with New Rows and 'remarks' Column:")
print(df)