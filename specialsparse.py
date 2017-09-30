print"DIVYA ROSE RAJU"
print"\t","\t","SPARSE MATRIX"
m=input("rows:")
n=input("colomn:")
x=input("enter number of non-zero elements:")
d={}
for i in range(x):
  a=input("row:")
  b=input("colomn:")
  d[(a,b)]=input("enter non-zero element :")
print d
l=d.keys()
for i in range(m):
    for j in range(n):
       print d.get((i,j),0),
    print
