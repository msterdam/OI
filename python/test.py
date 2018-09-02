print("hello world\n")
print("My name is {0}, and I am {1} years old".format("Robert","16"))
name="Robert"
age=16
print("My name is {}, and I am {} years old".format(name,age))#pythoon自动换行
print(name+" is "+str(age)+" years old")
print('{0:.3f}'.format(1.0/3))
print('{0:_^11}'.format('hello'))
print('{a} wrote {b}'.format(a='Swaroop', b='A Byte of Python'))
print('a', end='')
print('b', end='')#取消换行
print("")
print("What\'s your name?")
print(r"What\'s your name?")#取消转义
print("This is the first sentence. \
       This is the second sentence.")#两句之间不换行
print("""This is the first line.
This is the second line""")#保留原格式
