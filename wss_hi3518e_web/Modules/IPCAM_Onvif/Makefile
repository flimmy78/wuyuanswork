include ../../config.local

CGI_LIB = MOD_Onvif.a

CGI_OBJ =\
		IPCAM_Onvif.o\
		onvifDeviceManagercallback.o\
		onvifMediacallback.o\
		onvifDiscoverycallback.o\
		onvifImageingcallback.o\
		onvifPtz.o
ifeq ($(ISMAKE_ONVIF), yes)
all:  $(CGI_LIB)
else
all:
	@echo -e "\033[31mISMAKE_ONVIF is not yes\033[0m"
endif

$(CGI_LIB): $(CGI_OBJ)
	$(AR) cr  $(CGI_LIB)  $(CGI_OBJ)
	$(STRIP) $(CGI_LIB)
	cp $(CGI_LIB) ../../$(LIBDIR)

%.o: %.c
	$(CC) -I./ -I../../include -c $< 
install:
	cp -rf *.a ../$(LIBDIR) 
clean:
	rm -rf $(CGI_LIB) *.o ../../$(LIBDIR)/$(CGI_LIB)
	
