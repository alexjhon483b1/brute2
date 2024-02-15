#!/bin/bash

start_num="50000"
end_num="55000"

seq  "$start_num" "$end_num" | parallel -j 50 python3 500.py {}

