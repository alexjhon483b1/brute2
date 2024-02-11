#include <stdio.h>
#include <curl/curl.h>

// Callback function to handle response headers
size_t handle_headers(char *buffer, size_t size, size_t nitems, void *userdata) {
    (void)userdata;  // Unused parameter

    size_t total_size = size * nitems;
    printf("%.*s", (int)total_size, buffer);  // Print the headers

    return total_size;
}

int main(int argc, char *argv[]) {
    if (argc != 1) {
        fprintf(stderr, "Usage: %s  \n", argv[0]);
        return 1;
    }

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Failed to initialize libcurl\n");
        return 1;
    }

    // Set the URL
    curl_easy_setopt(curl, CURLOPT_URL, "https://accounts.google.com/AddSession?hl=en&continue=https://www.google.com/&ec=GAlAmgQ&authuser=0");

    // Enable HTTP/2
    curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_2);

    // Set the host and other headers
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Host: accounts.google.com");
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (X11; Linux x86_64; rv:100.0) Gecko/20100101 Firefox/100.0");
    const char *cookieValue = argv[2];
    

    // ... (other headers)
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    // Set the callback function to handle headers
    curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, handle_headers);

    // Perform the request
    res = curl_easy_perform(curl);

    // Clean up
    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);

    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        return 1;
    }

    curl_global_cleanup();

    return 0;
}

