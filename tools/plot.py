
import pandas as pd
import matplotlib.pyplot as plt

df=pd.read_csv("metrics.csv")
w=df[df.op=="write"]
plt.plot(w.latency)
plt.title("Write Latency")
plt.xlabel("Ops")
plt.ylabel("Latency(us)")
plt.savefig("diagrams/write_latency.png")
