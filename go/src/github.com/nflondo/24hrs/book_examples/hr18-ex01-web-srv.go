package main

import (
	"net/http"
)
// takes a responseWriter and a pointer to the request.  A pointer would allow 
// to manipulate the request within the function before returning a response to
// the client
func helloWorld(w http.ResponseWriter, r *http.Request) {
	// By default if a request is made to non-existent path, / is called and 200 is returned,
	// so this check will cause a 404 for non-exstent paths
	if r.URL.Path != "/" {
		http.NotFound(w, r)
		return
	}
	// set header to inform client content type is going to be json
	w.Header().Set("Content-Type", "application/json; charset=utf-8")
	//Write method used to write the response, it includes status, headers, and
	//body.  []byte initializes a slice and converts the string value into bytes
	// Write method expects a slice of bytes.
	// write the response last
//	w.Write([]byte("Hello World\n"))
	w.Write([]byte(`{"hello": "world"}`))
}

func main() {
	//Handlefunc creates a route: / and defines how to respond to that path
	http.HandleFunc("/", helloWorld)
	// starts a server to respond to a client that listens on localhost and port 8000
	http.ListenAndServe(":8000", nil)
}