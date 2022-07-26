# SimpleWebApp

First exercise in creating apps in modern C++.

Based on Crow web framework

## Build

Clone:
```bash
git clone <this repo>
```

Add dependencies:
```bash
cd <cloned repo> && mkdir dependencies
```
Add Crow dependency:
```bash
cd dependencies && git clone https://github.com/CrowCpp/Crow.git
```
Build:
```bash
cd .. && mkdir build && cd build && make
```

## Test requests

Start the app:
```bash
# in <cloned repo>/build
./simpleWebApp
```

GET request:
```bash
http GET http://localhost:18080
```

POST request:
```bash
http POST http://localhost:18080
```
