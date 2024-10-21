# Q.2 
# A) Write a Python program to create box plots to see how each feature i.e. 
# Sepal Length, Sepal Width, Petal Length, Petal Width are distributed across 
# the three species. (Use iris.csv dataset)

import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns


iris_df = pd.read_csv('iris.csv')


fig, axes = plt.subplots(2, 2, figsize=(12, 10))
fig.suptitle('Distribution of Iris Features Across Species', fontsize=16)


features = ['Sepal Length', 'Sepal Width', 'Petal Length', 'Petal Width']


for i, feature in enumerate(features):
    row = i // 2
    col = i % 2
    sns.boxplot(x='Species', y=feature, data=iris_df, ax=axes[row, col])
    axes[row, col].set_title(f'{feature} Distribution')
    axes[row, col].set_xlabel('Species')
    axes[row, col].set_ylabel(feature)

# Adjust layout and display the plot
plt.tight_layout()
plt.show()