#include <stdio.h>

/*lua 解释器*/
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

//gcc luaTest.c -o luaTest -llua -lm -ldl  --> 编译

int main(int argc, char* argv[])
{   
    lua_State *L = luaL_newstate();  /* opens Lua */  
    luaL_openlibs(L);

    int retLoad = luaL_loadfile(L, "hello.lua");
    if (retLoad == 0)
    {
        printf("load file success retLoad:%d\n", retLoad);
    }

    if (retLoad || lua_pcall(L, 0, 0, 0))
    {
        printf("error %s\n", lua_tostring(L, -1));
        return -1;
    }

    lua_close(L);
    return 0;
}
