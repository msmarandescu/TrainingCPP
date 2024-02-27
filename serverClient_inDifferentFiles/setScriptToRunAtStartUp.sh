#!/bin/bash

#copiaza scriptul startupScript.sh in locatia /etc/init.d/
sudo cp startupScript.sh /etc/init.d/

#seteaza scriptul pentru a fi rulat la pornirea sistemului:
sudo update-rc.d startupScript.sh defaults
