
import os

x = os.listdir(".")
for i in x:
    if i.endswith(".c") or i.endswith(".h"):
        a = i.split(".")
        os.system(f"mv {i} {a[0]}_bonus.{a[1]}")
