#include "crow.h"
#include "string"
#include "memory"

template <typename Impl>
class HttpResponse
{
private:
    Impl implementation;
public:
    HttpResponse() 
        : implementation(Impl())
    {}

    std::string getContents()
    {
        return implementation.getContents();
    }
};

class Method
{
public:
    virtual const std::string getContents() const = 0;
};

class Get: Method
{
public:
    const std::string getContents() const
    {
        return "This is GET response";
    }
};

class Post: Method
{
public:
    const std::string getContents() const
    {
        return "This is POST response";
    }
};

int main()
{
    crow::SimpleApp app;

    // test instantiating with unique_ptr
    auto getResp = std::make_unique<HttpResponse<Get>>();
    // test instantiating with new keyword
    auto* postResp = new HttpResponse<Post>();

    CROW_ROUTE(app, "/").methods(crow::HTTPMethod::GET)([&](){
        return getResp->getContents();
    });

    CROW_ROUTE(app, "/").methods(crow::HTTPMethod::POST)([&](){
        return postResp->getContents();
    });

    app.port(18080).multithreaded().run();

    delete postResp;
}
