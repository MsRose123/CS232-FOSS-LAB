print "D"+"ivya"
import string
x=raw_input("Enter a sentence:")+" "
y=raw_input("enter word:")
count=0
m=len(x)
n=len(y)
b=0
while b<=m :
 a=string.find(x,y,b,m)
 if a!=-1 :
  if a==0 and x[n]==" " :
     count=count+1
  elif x[a-1]==" " and x[a+n]==" ":
     count=count+1
  elif x[a-1]==" " and x[a+n+1]==".":
     count=count+1
  else :
     break
  b=b+a+n
print"Occurences of %s in %s is %d times" % (y,x,count)
