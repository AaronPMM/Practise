-- �򵥵� table
mytable = {}
print("mytable �������� ",type(mytable))

mytable[1]= "Lua"
mytable["wow"] = "�޸�ǰ"
print("mytable ����Ϊ 1 ��Ԫ���� ", mytable[1])
print("mytable ����Ϊ wow ��Ԫ���� ", mytable["wow"])

-- alternatetable��mytable����ָͬһ�� table
alternatetable = mytable

print("alternatetable ����Ϊ 1 ��Ԫ���� ", alternatetable[1])
print("mytable ����Ϊ wow ��Ԫ���� ", alternatetable["wow"])

alternatetable["wow"] = "�޸ĺ�"

print("mytable ����Ϊ wow ��Ԫ���� ", mytable["wow"])

-- �ͷű���
alternatetable = nil
print("alternatetable �� ", alternatetable)

-- mytable ��Ȼ���Է���
print("mytable ����Ϊ wow ��Ԫ���� ", mytable["wow"])

mytable = nil
print("mytable �� ", mytable)

fruits = {"banana","orange","apple"}

-- ��ĩβ����
table.insert(fruits,"mango")
print("����Ϊ 4 ��Ԫ��Ϊ ",fruits[4])
print(fruits[1],fruits[2],fruits[3],fruits[4])

-- ������Ϊ 2 �ļ�������
table.insert(fruits,2,"grapes")
print("����Ϊ 2 ��Ԫ��Ϊ ",fruits[2])
print(fruits[1],fruits[2],fruits[3],fruits[4])

print("���һ��Ԫ��Ϊ ",fruits[5])
table.remove(fruits)
print("�Ƴ������һ��Ԫ��Ϊ ",fruits[5])
print(fruits[1],fruits[2],fruits[3],fruits[4])
