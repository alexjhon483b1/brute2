
x=$(./cookie.sh)
curl -L -I GET "https://accounts.google.com/ServiceLogin?continue=https%3A%2F%2Fwww.google.com%2F&hl=en" \
     -H "Host: accounts.google.com" \
     -H "Cookie: $x" \
     -H "Upgrade-Insecure-Requests: 1" \
     -H "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/121.0.6167.160 Safari/537.36" \
     -H "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7" \
     -H "X-Client-Data: CK7dygE=" \
     -H "Sec-Fetch-Site: none" \
     -H "Sec-Fetch-Mode: navigate" \
     -H "Sec-Fetch-User: ?1" \
     -H "Sec-Fetch-Dest: document" \
     -H "Sec-Ch-Ua: \"Chromium\";v=\"121\", \"Not A(Brand\";v=\"99\"" \
     -H "Sec-Ch-Ua-Mobile: ?0" \
     -H "Sec-Ch-Ua-Full-Version: \"\"" \
     -H "Sec-Ch-Ua-Arch: \"\"" \
     -H "Sec-Ch-Ua-Platform: \"Linux\"" \
     -H "Sec-Ch-Ua-Platform-Version: \"\"" \
     -H "Sec-Ch-Ua-Model: \"\"" \
     -H "Sec-Ch-Ua-Bitness: \"\"" \
     -H "Sec-Ch-Ua-Wow64: ?0" \
     -H "Sec-Ch-Ua-Full-Version-List: " \
     -H "Accept-Encoding: gzip, deflate, br" \
     -H "Accept-Language: en-US,en;q=0.9" \
     -H "Priority: u=0, i" -v 
