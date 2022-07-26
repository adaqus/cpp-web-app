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

    CROW_ROUTE(app, "/").methods(crow::HTTPMethod::GET)([](){
        // this is just to test instantiating with unique_ptr
        auto resp = std::make_unique<HttpResponse<Get>>();
        return resp->getContents();
    });

    CROW_ROUTE(app, "/").methods(crow::HTTPMethod::POST)([](){
        // this is just to test instantiating with new keyword (leaks memory)
        auto* resp = new HttpResponse<Post>();
        return resp->getContents();
    });

    app.port(18080).multithreaded().run();
}
