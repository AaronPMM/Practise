#include <stdio.h>
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
int main()
{
    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    int retLoad = luaL_loadfile(L, "test.lua");
    if (retLoad == 0)
    {
        printf("load file success retLoad:%d\n", retLoad);
    }
    if (retLoad || lua_pcall(L, 0, 0, 0))
    {
        printf("error %s\n", lua_tostring(L, -1));
        return -1;
    }

    printf("读取lua table中对应的值\n");
    //将全局变量mytable压入栈
    lua_getglobal(L, "mytable");
    //压入表中的key
    lua_pushstring(L, "name");
    
    //lua_gettable会在栈顶取出一个元素并且返回把查找到的值压入栈顶
    lua_gettable(L, 1);
    const char *name = lua_tostring(L, -1); //在栈顶取出数据
    printf("name:%s\n", name);
    
    lua_pushstring(L,"id");//压入id
    lua_gettable(L, 1);//在lua mytable表中取值返回到栈顶
    int id = lua_tonumber(L, -1); //在栈顶取出数据
    printf("id:%d\n", id);

    lua_close(L);
    return 0;
}