#!/bin/bash
process_id=$(ps | grep so_long | awk 'NR==1 {print $1}')
leaks $process_id
