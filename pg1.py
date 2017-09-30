m=input("r=")
n=input("c=")
a=[]
c=[]
print "Enter elements"
for i in range(m):
   l=[]
   for j in range(n):
       x=input()
       l.append(x)
   a.append(l)
i=0
j=0
for i in range(n):
    b=[]
    for j in range(m):
        b.append(a[j][i])
    c.append(b)
for i in range(n):
   for j in range(m):
      print c[i][j],
   print 
       
