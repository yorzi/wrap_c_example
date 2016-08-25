#include <stdlib.h>
#include <ruby.h>

static VALUE rb_mWrapCExample;
static VALUE rb_cGreeting;

static VALUE
greeting_hello(VALUE self) {
  /*
   * Setup for function located in ../../static_libs/hello_user.c
   */
  char *  greeting(char *);

  /*
   * return a string VALUE from a char * that ruby can handle and assign to variables
   */
  return rb_str_new2(greeting(RSTRING_PTR(rb_iv_get(self, "@uri"))));
}

extern int gen_default_key(const char* uri,
  const char* crypt_key,
  int url_valid_time,
  char*  res_key);

extern int verify_url(const char* url, const char* key);

static VALUE
greeting_init(VALUE self, VALUE name, VALUE key, VALUE time) {
  rb_iv_set(self, "@uri", name);
  rb_iv_set(self, "@key", key);
  rb_iv_set(self, "@time", time);

  return self;
}

static VALUE genkey(VALUE self) {
  static char out[200];
  gen_default_key(RSTRING_PTR(rb_iv_get(self, "@uri")), RSTRING_PTR(rb_iv_get(self, "@key")), FIX2INT(rb_iv_get(self, "@time")), out);
  return rb_str_new2(out);
}

static VALUE verify(VALUE self) {
  int i = verify_url(RSTRING_PTR(rb_iv_get(self, "@uri")), RSTRING_PTR(rb_iv_get(self, "@key")));
  return i == 0 ? Qtrue : Qfalse;
}

void
Init_wrap_c_example_c() {
  rb_mWrapCExample = rb_define_module("WrapCExample");
  rb_cGreeting     = rb_define_class_under(rb_mWrapCExample, "Greeting", rb_cObject);

  rb_define_method(rb_cGreeting, "initialize", greeting_init, 3);
  rb_define_method(rb_cGreeting, "hello", greeting_hello, 0);
  rb_define_method(rb_cGreeting, "genkey", genkey, 0);
  rb_define_method(rb_cGreeting, "verify", verify, 0);
}
