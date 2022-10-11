function f(x)
	print("function")
	return x * 2
end

for i=1, f(5)
do
	print(i)
end


for i=10,1,-1 do
  print(i)
end


array = {"Lua", "Tutorial"}

for key,value in ipairs(array)
do
  print("key:", key)
  print("value:",value)
  print(key,value)
end
