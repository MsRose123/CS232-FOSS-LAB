m=input("r=")
n=input("c=")
l=[]
s1=0
s2=0
print "Enter elements"
for i in range(m):
   a=[]
   for j in range(n):
       x=input()
       a.append(x)
   l.append(a)
for i in range(m):
    sum=0
    for j in range(n):
       sum=sum+l[i][j]
    print "sum of row ",i+1,"=",sum
s=0
for j in range(n):
   for i in range(m):
      s=s+l[i][j]
   print "Sum of column",j+1,"=",s
   s=0
for i in range(m):
   for j in range(n):
      if i==j:
        s1=s1+l[i][j]
      elif (i+j)==m-1:
        s2=s2+l[i][j]
print s1
print s2
         
      
