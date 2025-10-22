#include "httplib.h"
#include "gtest/gtest.h"

static httplib::Client cli("localhost",8080);

TEST(REST_API_TEST, BasicTest)
{
  auto res = cli.Get("/vkthrk/hello");
  ASSERT_EQ("Hello World!", res->body);
}

TEST(REST_API_TEST, InvalidRequest)
{
  auto res = cli.Get("/hello");
  ASSERT_EQ(404, res->status);
}

TEST(REST_API_TEST, InvalidRequestPath)
{
  auto res = cli.Get("/vkthrk/hi");
  ASSERT_EQ(404, res->status);
}

