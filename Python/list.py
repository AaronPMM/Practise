motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles)

# 列表长度
print(len(motorcycles))

# 修改列表
motorcycles[0] = 'ducati'
print(motorcycles)

# 在列表末尾添加元素
motorcycles.append('ducati')
print(motorcycles)

# 在列表中插入元素
motorcycles.insert(0, 'ducati')
print(motorcycles)

# 使用 del 语句删除元素
del motorcycles[0]
print(motorcycles)

# 使用 pop() 方法删除元素
popped_motorcycles = motorcycles.pop()
print(motorcycles)
print(popped_motorcycles)


# 使用 pop() 方法删除任意元素
popped_motorcycles = motorcycles.pop(2)
print(motorcycles)
print(popped_motorcycles)

# 使用方法sort() 对列表永久排序
cars = ['bmw', 'audi', 'toyota', 'subaru']
cars.sort()
print(cars)

# 使用函数 sorted() 对列表临时排序
cars1 = ['bmw', 'audi', 'toyota', 'subaru']
print(sorted(cars1))
print(cars1)

# 反转列表
cars3 = ['bmw', 'audi', 'toyota', 'subaru']

cars.reverse()
print(cars3)

# 使用 len() 获取列表长度
cars2 = ['bmw', 'audi', 'toyota', 'subaru']
print(len(cars2))
