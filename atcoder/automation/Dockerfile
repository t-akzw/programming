FROM continuumio/anaconda3

ENV APP_PATH=/app
RUN mkdir -p $APP_PATH
WORKDIR $APP_PATH

RUN pip install japanize-matplotlib
RUN pip install beautifulsoup4

RUN /opt/conda/bin/conda install jupyter -y --quiet &&\
  mkdir /opt/notebooks

EXPOSE 8888
#CMD ["/opt/conda/bin/jupyter", "notebook", "--notebook-dir=/opt/notebooks", "--ip='*'", "--port=8888", "--no-browser"]
