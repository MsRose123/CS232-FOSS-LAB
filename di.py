print "D"+"ivya"
import string
x=raw_input("Enter a sentence:")+" "
y=raw_input("enter word:")+" "
count=0
m=len(x)
n=len(y)
for b in range (0,m):
 a=string.find(x,y,b,m)
 if a!=-1 :
  if a==0 :
     count=count+1
  elif x[a-1]==" ":
     count=count+1
  else :
     break
  b=b+a+n
print"Occurences of %s in %s is %d times" % (y,x,count)
