git add *
git commit -m $1
git push origin

docker build --no-cache -t keros/drupal-test .
docker run -d -p 80:80 -p 3306:3306 keros/drupal-test
