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
    lua_State *L = luaL_newstate();             // 1. �إ� State ���A��
    luaL_openlibs(L);                           // 2. ���J Lua �򥻨禡�w
	
    if (luaL_loadfile(L, argv[1]))              // 3. ���J argv[1] ���w�� Lua �{���� (�٨S����)
	  error(L, "luaL_loadfile() failed");      

    if (lua_pcall(L, 0, 0, 0))                  // 4. ������J�� Lua �{��
	  error(L, "lua_pcall() failed");

    lua_close(L);                               // 5. ����
    return 0;
}
