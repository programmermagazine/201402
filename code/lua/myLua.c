#include <stdlib.h>
#include <stdio.h>

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

void error(lua_State *L, char *msg){
	fprintf(stderr, "\nFATAL ERROR:\n  %s: %s\n\n", msg, lua_tostring(L, -1));
	exit(1);
}

int main(int argc, char *argv[])
{
    lua_State *L = luaL_newstate();             // 1. 建立 State 狀態機
    luaL_openlibs(L);                           // 2. 載入 Lua 基本函式庫
	
    if (luaL_loadfile(L, argv[1]))              // 3. 載入 argv[1] 指定的 Lua 程式檔 (還沒執行)
	  error(L, "luaL_loadfile() failed");      

    if (lua_pcall(L, 0, 0, 0))                  // 4. 執行載入的 Lua 程式
	  error(L, "lua_pcall() failed");

    lua_close(L);                               // 5. 結束
    return 0;
}
