

OTOOL = otool

NM = nm

all:
	make -C $(OTOOL)
	make -C $(NM)

nm:
	make -C $(NM)

otool:
	make -C $(OTOOL)

clean:
	make clean -C $(NM)
	make clean -C $(OTOOL)

fclean:
	make fclean -C $(NM)
	make fclean -C $(OTOOL)

re: fclean all
