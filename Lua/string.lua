-- 字符串替换
a = "one string"
b = string.gsub(a, "one", "another")
print(a)
print(b)

-- 获取字符串的长度
a = "hello"
print(#a)
print(#"good bye")

-- 字符串连接 ..
print("Hello ".."World")


-- 任何有效字符串参与的算术运算都会被作为浮点运算处理
print("10"+1)

-- 字符串转换成数值
a = tonumber(" -3")
print(a)

a = tonumber(" 10e4")
print(a)

a = tonumber(" 10e")
print(a)

a = tonumber("0x1.3p-4")
print(a)

-- 各进制转十进制输出
a = tonumber("100101", 2) -- 二级制转十进制输出
print(a)

a = tonumber("fff", 16) -- 十六级制转十进制输出
print(a)

a = tonumber("-ZZ", 36) --
print(a)

a = tonumber("987", 8)  -- 八进制转十进制输出
print(a)

-- 将数值转换成字符串
print(tostring(10) == "10")
