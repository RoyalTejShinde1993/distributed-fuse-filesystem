
#!/bin/bash
echo "op,latency" > metrics.csv
for i in {1..200}; do
  START=$(date +%s%N)
  echo "data$i" > mount/file$i
  END=$(date +%s%N)
  echo "write,$((($END-$START)/1000))" >> metrics.csv
done
