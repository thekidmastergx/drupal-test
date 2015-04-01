FROM tutum/lamp:latest
RUN rm -fr /app && git clone https://github.com/thekidmastergx/drupal-test /app
RUN chmod o+w /app/sites/default
RUN chmod o+w /app/sites/default/settings.php
EXPOSE 80 3306
CMD ["/run.sh"]
