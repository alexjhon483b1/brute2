this is an incomplete project that i wish to complete 
later
this project is about brute forcing phone number from 
gmail forget password.
the fuck.c first retrieves the cookie from mentioned
url in the code.
then cookie.sh parses the cookie
then main.sh go to new url with the cookie 
and it uses -L to go to all redirects.
until it reaches 200.
the first 200 is the form where gmail is 
to be submitted.
i have made the project till this. 

from there i have seen firefox request tab
a payload in raw view. the gmail is submitted 
with a dynamic payload. 
i have to make that dynamic payload. 
from there and so on....

NOTE: C compiled code takes argument from bash
only if `grep` is used. it won't work if `awk` 
is used
