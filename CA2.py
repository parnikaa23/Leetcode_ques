import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import scipy.stats as stats

# Load the dataset with low_memory=False to avoid dtype warning
df = pd.read_csv("C:/Users/parni/OneDrive/Desktop/numpy/Crash_Reporting_-_Drivers_Data.csv", low_memory=False)

# Display column names to verify correctness
print("Columns in the dataset:")
for col in df.columns:
    print(f"'{col}'")

# Clean the dataset
df = df.dropna(subset=['Driver At Fault'])  # Drop rows with missing 'Driver At Fault'
df.fillna(value={'Weather': 'Unknown'}, inplace=True)  # Replace missing 'Weather' with 'Unknown'

# Ensure 'Driver Age' column exists and is numeric
if 'Driver Age' in df.columns:
    df['Driver Age'] = pd.to_numeric(df['Driver Age'], errors='coerce')
    df = df.dropna(subset=['Driver Age'])  # Drop rows where 'Driver Age' couldn't be converted
else:
    print("Column 'Driver Age' not found in the dataset.")

# Summary statistics
print("\nSummary Statistics:\n")
print(df.describe(include='all'))

# Unique values for each object column
print("\nUnique values in object columns:\n")
for col in df.select_dtypes(include='object').columns:
    print(f"{col}: {df[col].nunique()} unique values")

# Plot: Top 10 Driver Distractions
plt.figure(figsize=(10,6))
sns.countplot(
    data=df,
    y='Driver Distracted By',
    order=df['Driver Distracted By'].value_counts().head(10).index,
    palette='viridis'
)
plt.title('Top 10 Driver Distractions')
plt.xlabel('Count')
plt.ylabel('Distraction Factor')
plt.tight_layout()
plt.show()

# Heatmap for correlation
plt.figure(figsize=(10,6))
sns.heatmap(df.corr(numeric_only=True), annot=True, cmap='coolwarm')
plt.title('Correlation Matrix')
plt.tight_layout()
plt.show()

# Histogram: Driver Age Distribution
if 'Driver Age' in df.columns:
    sns.histplot(df['Driver Age'], bins=30, kde=True)
    plt.title('Driver Age Distribution')
    plt.xlabel('Age')
    plt.ylabel('Frequency')
    plt.tight_layout()
    plt.show()

# Pie Chart: Driver At Fault Distribution
plt.figure(figsize=(6,6))
fault_counts = df['Driver At Fault'].value_counts()
plt.pie(fault_counts, labels=fault_counts.index, autopct='%1.1f%%', startangle=90, colors=sns.color_palette('pastel'))
plt.title('Driver At Fault Distribution')
plt.tight_layout()
plt.show()

# Bar Plot: Weather Conditions
plt.figure(figsize=(10,6))
sns.countplot(data=df, x='Weather', order=df['Weather'].value_counts().index)
plt.title('Crash Distribution by Weather')
plt.xlabel('Weather')
plt.ylabel('Count')
plt.xticks(rotation=45)
plt.tight_layout()
plt.show()

# Box Plot: Driver Age vs At Fault
if 'Driver Age' in df.columns:
    plt.figure(figsize=(8,6))
    sns.boxplot(data=df, x='Driver At Fault', y='Driver Age', palette='Set2')
    plt.title('Driver Age vs Driver At Fault')
    plt.tight_layout()
    plt.show()

# Hypothesis Testing: Compare mean ages of drivers at fault vs not at fault
df_at_fault = df[df['Driver At Fault'] == 'Yes']['Driver Age']
df_not_at_fault = df[df['Driver At Fault'] == 'No']['Driver Age']

t_stat, p_value = stats.ttest_ind(df_at_fault, df_not_at_fault)

print("\nT-test result for Driver Age:")
print(f"T-statistic: {t_stat}")
print(f"P-value: {p_value}")

if p_value < 0.05:
    print("There is a significant difference in the mean age of drivers at fault vs. not at fault.")
else:
    print("There is no significant difference in the mean age of drivers at fault vs. not at fault.")
