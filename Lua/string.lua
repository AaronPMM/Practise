-- �ַ����滻
a = "one string"
b = string.gsub(a, "one", "another")
print(a)
print(b)

-- ��ȡ�ַ����ĳ���
a = "hello"
print(#a)
print(#"good bye")

-- �ַ������� ..
print("Hello ".."World")


-- �κ���Ч�ַ���������������㶼�ᱻ��Ϊ�������㴦��
print("10"+1)

-- �ַ���ת������ֵ
a = tonumber(" -3")
print(a)

a = tonumber(" 10e4")
print(a)

a = tonumber(" 10e")
print(a)

a = tonumber("0x1.3p-4")
print(a)

-- ������תʮ�������
a = tonumber("100101", 2) -- ������תʮ�������
print(a)

a = tonumber("fff", 16) -- ʮ������תʮ�������
print(a)

a = tonumber("-ZZ", 36) --
print(a)

a = tonumber("987", 8)  -- �˽���תʮ�������
print(a)

-- ����ֵת�����ַ���
print(tostring(10) == "10")
