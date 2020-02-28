#include <node_api.h>
#include <stdio.h>

napi_value SayHello(napi_env env, napi_callback_info info) {
  printf("Hello, N-API.\n");
  napi_value world;
  napi_create_string_utf8(env, "string napi_create_string_utf8", 100, &world); // 100这个参数值表示给字符串分配的空间大小。太长会出现乱码。
  return world;
}

napi_value Init(napi_env env, napi_value exports) {
  napi_status status;

  napi_value fn;
  status = napi_create_function(env, NULL, 0, SayHello, NULL, &fn);
  if (status != napi_ok) return NULL;

  status = napi_set_named_property(env, exports, "sayHello", fn);
  if (status != napi_ok) return NULL;

  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)