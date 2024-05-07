cc = gcc
flag = -Wall -g 
APP : main.o adminLogin.o userLogin.o adminServices.o addRemoveBus.o addRemoveRoute.o approveRejectBusPassMain.o busManager.o userFeedBack.o requestNewRouteApplication.o newUser.o existingUser.o busandRouteInfo.o userServices.o requestNewRoute.o feedBack.o busPass.o viewAll.o
	$(cc) $(flag) main.o adminLogin.o userLogin.o adminServices.o addRemoveBus.o addRemoveRoute.o approveRejectBusPassMain.o busManager.o userFeedBack.o requestNewRouteApplication.o newUser.o existingUser.o busandRouteInfo.o userServices.o requestNewRoute.o feedBack.o busPass.o viewAll.o -o APP
main.o : main.c
	$(cc) $(flag) -c main.c
adminLogin.o : adminLogin.c
	$(cc) $(flag) -c adminLogin.c
userLogin.o : userLogin.c
	$(cc) $(flag) -c userLogin.c
adminServices.o : adminServices.c
	$(cc) $(flag) -c adminServices.c
addRemoveBus.o : addRemoveBus.c
	$(cc) $(flag) -c addRemoveBus.c
addRemoveRoute.o : addRemoveRoute.c
	$(cc) $(flag) -c addRemoveRoute.c
approveRejectBusPassMain.o : approveRejectBusPassMain.c
	$(cc) $(flag) -c approveRejectBusPassMain.c
busManager.o : busManager.c
	$(cc) $(flag) -c busManager.c
userFeedBack.o : userFeedBack.c
	$(cc) $(flag) -c userFeedBack.c
requestNewRouteApplication.o : requestNewRouteApplication.c
	$(cc) $(flag) -c requestNewRouteApplication.c 
newUser.o : newUser.c
	$(cc) $(flag) -c newUser.c
existingUser.o : existingUser.c
	$(cc) $(flag) -c existingUser.c
busandRouteInfo.o : busandRouteInfo.c
	$(cc) $(flag) -c busandRouteInfo.c
userServices.o : userServices.c
	$(cc) $(flag) -c userServices.c
requestNewRoute.o : requestNewRoute.c
	$(cc) $(flag) -c requestNewRoute.c
feedBack.o : feedBack.c
	$(cc) $(flag) -c feedBack.c
busPass.o : busPass.c
	$(cc) $(flag) -c busPass.c
viewAll.o : viewAll.c
	$(cc) $(flag) -c viewAll.c

#phony Target	
clean:
	
	rm -f *.o
	rm -f APP
