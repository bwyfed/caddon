#include <node_api.h>
#include <stdio.h>

// #pragma comment(lib, "mydll.lib")
// int myAdd(int a, int b);
// int mySub(int a, int b);

napi_value SayHello(napi_env env, napi_callback_info info) {
  printf("Hello, N-API.\n");
  // int a = 5, b = 6;
	// printf("调用dll函数myAdd的函数结果：myAdd(%d, %d) = %d\n", a, b, myAdd(a, b));
	// printf("调用dll函数mySub的函数结果：mySub(%d, %d) = %d", a, b, mySub(a, b));
  napi_value world;
  napi_create_string_utf8(env, "string napi_create_string_utf8", NAPI_AUTO_LENGTH, &world); // 100这个参数值表示给字符串分配的空间大小。太长会出现乱码。
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