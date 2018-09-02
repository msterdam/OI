x=1
y=1
def sayhi():
    print("Hi there!")
def printf():
    y=2
    print(y)
    global x
    print(x)
sayhi()
for i in range(1,10):#[1,10)
    print(i)
printf()
def say(message, times=1):
    print(message * times)
say('Hello')
say('World', 5)
print("")
def func(a, b=5, c=10):
    print('a is', a, 'and b is', b, 'and c is', c)
    func(3, 7)
    func(25, c=24)
    func(c=50, a=100)
print("")
def total(a=5, *numbers, **phonebook):
    print('a', a)
    #遍历元组中的所有项目
    for single_item in numbers:
        print('single_item', single_item)
        #遍历字典中的所有项目
    for first_part, second_part in phonebook.items():
        print(first_part,second_part)
print(total(10,1,2,3,Jack=1123,John=2231,Inge=1560))

