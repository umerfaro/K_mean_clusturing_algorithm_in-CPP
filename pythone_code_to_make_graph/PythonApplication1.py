

import matplotlib.pyplot as plt
import pandas as pd


df = pd.read_csv("D:\\programming\\data structure 4th semester\\assignment 1 again updated\\assignment 1 again updated\\output.csv", header=None, names=["X", "Y", "Cluster"])


for i in range(1, df["Cluster"].max() + 1):
    x = df[df["Cluster"] == i]["X"]
    y = df[df["Cluster"] == i]["Y"]
    plt.scatter(x, y, label=f"Cluster {i}")
    plt.xlabel("Annual income (k$)")
plt.ylabel("Spending Score (1-100)")
plt.title("Clustered: spending (y) vs income (x)")


plt.legend()
plt.show()





from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("D:\\programming\\data structure 4th semester\\assignment 1 again updated\\assignment 1 again updated\\output2.csv", header=None, names=["X", "Y","Z", "Cluster"])

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

for i in range(1, df["Cluster"].max() + 1):
    x = df[df["Cluster"] == i]["X"]
    y = df[df["Cluster"] == i]["Y"]
    z = df[df["Cluster"] == i]["Z"]
    ax.scatter(x, y, z, label=f"Cluster {i}")
    ax.set_xlabel("AGE")
ax.set_ylabel("Annual income")
ax.set_zlabel("Spending Score")
ax.set_title("Clustered: AGE (x) vs Annual income (y) vs Spending score(z)")

plt.legend()
plt.show()
