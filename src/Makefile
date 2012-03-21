#
# OMNeT++/OMNEST Makefile for libnumbat
#
# This file was generated with the command:
#  opp_makemake -f --deep --make-so -I/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2/src/util/headerserializers/headers -I/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2/src/networklayer/arp -I/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2/src/transport/sctp -I/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2/src/world -I/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2/src/transport/contract -I/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2/src/linklayer/mfcore -I/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2/src/linklayer/ethernet -I/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2/src/networklayer/ted -I/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2/src/util -I/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2/src/linklayer/ieee80211/mac -I/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2/src/networklayer/common -I/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2/src/networklayer/ipv6 -I/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2/src/applications/pingapp -I/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2/src/networklayer/ldp -I/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2/src/transport/tcp -I/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2/src/util/headerserializers -I/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2/src/networklayer/rsvp_te -I/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2/src/transport/udp -I/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2/src/networklayer/ipv4 -I/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2/src/networklayer/icmpv6 -I/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2/src/base -I../../Vlans/src/linklayer -I/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2/src/networklayer/contract -I../../PON/src/common -I/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2/src/networklayer/manetrouting/base -I/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2/src/networklayer/mpls -I/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2/src/linklayer/contract -L../../Vlans/out/$(CONFIGNAME)/src -L/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2/out/$(CONFIGNAME)/src -L../../PON/out/$(CONFIGNAME)/src -L../../PON/out/$(CONFIGNAME) -lVlans -linet -lPON -lPON -KVLANS_PROJ=../../Vlans -KINETMANET_PROJ=/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2 -KPON_PROJ=../../PON
#

# Name of target to be created (-o option)
TARGET = libnumbat$(SHARED_LIB_SUFFIX)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I$(INETMANET_PROJ)/src/util/headerserializers/headers \
    -I$(INETMANET_PROJ)/src/networklayer/arp \
    -I$(INETMANET_PROJ)/src/transport/sctp \
    -I$(INETMANET_PROJ)/src/world \
    -I$(INETMANET_PROJ)/src/transport/contract \
    -I$(INETMANET_PROJ)/src/linklayer/mfcore \
    -I$(INETMANET_PROJ)/src/linklayer/ethernet \
    -I$(INETMANET_PROJ)/src/networklayer/ted \
    -I$(INETMANET_PROJ)/src/util \
    -I$(INETMANET_PROJ)/src/linklayer/ieee80211/mac \
    -I$(INETMANET_PROJ)/src/networklayer/common \
    -I$(INETMANET_PROJ)/src/networklayer/ipv6 \
    -I$(INETMANET_PROJ)/src/applications/pingapp \
    -I$(INETMANET_PROJ)/src/networklayer/ldp \
    -I$(INETMANET_PROJ)/src/transport/tcp \
    -I$(INETMANET_PROJ)/src/util/headerserializers \
    -I$(INETMANET_PROJ)/src/networklayer/rsvp_te \
    -I$(INETMANET_PROJ)/src/transport/udp \
    -I$(INETMANET_PROJ)/src/networklayer/ipv4 \
    -I$(INETMANET_PROJ)/src/networklayer/icmpv6 \
    -I$(INETMANET_PROJ)/src/base \
    -I../../Vlans/src/linklayer \
    -I$(INETMANET_PROJ)/src/networklayer/contract \
    -I../../PON/src/common \
    -I$(INETMANET_PROJ)/src/networklayer/manetrouting/base \
    -I$(INETMANET_PROJ)/src/networklayer/mpls \
    -I$(INETMANET_PROJ)/src/linklayer/contract \
    -I. \
    -Iipv6 \
    -Imobility \
    -Iport-win32 \
    -Iscripts \
    -Iutil \
    -Iwimax \
    -Iwimax/models

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L../../Vlans/out/$(CONFIGNAME)/src -L$(INETMANET_PROJ)/out/$(CONFIGNAME)/src -L../../PON/out/$(CONFIGNAME)/src -L../../PON/out/$(CONFIGNAME)  -lVlans -linet -lPON -lPON
LIBS += -Wl,-rpath,`abspath ../../Vlans/out/$(CONFIGNAME)/src` -Wl,-rpath,`abspath $(INETMANET_PROJ)/out/$(CONFIGNAME)/src` -Wl,-rpath,`abspath ../../PON/out/$(CONFIGNAME)/src` -Wl,-rpath,`abspath ../../PON/out/$(CONFIGNAME)`

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/ipv6/dhcpv6.o \
    $O/ipv6/Internet.o \
    $O/ipv6/ipv6disp.o \
    $O/ipv6/ipv6node.o \
    $O/ipv6/mip6.o \
    $O/ipv6/ra.o \
    $O/mobility/WiMaxBasicMobility.o \
    $O/mobility/WiMaxLineSegmentsMobilityBase.o \
    $O/mobility/WiMaxRandomWPMobility.o \
    $O/port-win32/addrpack.o \
    $O/util/fsm.o \
    $O/util/IPv6Addr.o \
    $O/util/logger.o \
    $O/util/ssinfo.o \
    $O/wimax/wmaxctrl.o \
    $O/wimax/wmaxmac.o \
    $O/wimax/wmaxmaccs.o \
    $O/wimax/wmaxphy.o \
    $O/wimax/wmaxradio.o \
    $O/ipv6/ipv6msg_m.o \
    $O/util/mih_m.o \
    $O/wimax/wmaxmsg_m.o

# Message files
MSGFILES = \
    ipv6/ipv6msg.msg \
    util/mih.msg \
    wimax/wmaxmsg.msg

# Other makefile variables (-K)
VLANS_PROJ=../../Vlans
INETMANET_PROJ=/media/data/Linux/omnet/inetmanet-inetmanet-00f64c2
PON_PROJ=../../PON

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppenvir$D $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $(TARGET)

$(TARGET) : $O/$(TARGET)
	ln -s -f $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@mkdir -p $O
	$(SHLIB_LD) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(LIBS) $(OMNETPP_LIBS) $(LDFLAGS)
	-$(CHCON) -t textrel_shlib_t $O/$(TARGET) || echo "You can probably safely ignore the above message."

.PHONY:

.SUFFIXES: .cc

$O/%.o: %.cc
	@mkdir -p $(dir $@)
	$(CXX) -c $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	-rm -rf $O
	-rm -f numbat numbat.exe libnumbat.so libnumbat.a libnumbat.dll libnumbat.dylib
	-rm -f ./*_m.cc ./*_m.h
	-rm -f ipv6/*_m.cc ipv6/*_m.h
	-rm -f mobility/*_m.cc mobility/*_m.h
	-rm -f port-win32/*_m.cc port-win32/*_m.h
	-rm -f scripts/*_m.cc scripts/*_m.h
	-rm -f util/*_m.cc util/*_m.h
	-rm -f wimax/*_m.cc wimax/*_m.h
	-rm -f wimax/models/*_m.cc wimax/models/*_m.h

cleanall: clean
	-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc ipv6/*.cc mobility/*.cc port-win32/*.cc scripts/*.cc util/*.cc wimax/*.cc wimax/models/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/ipv6/ipv6disp.o: ipv6/ipv6disp.cc \
	util/mih_m.h \
	ipv6/ipv6disp.h \
	util/Portable.h \
	util/IPv6Addr.h \
	ipv6/ipv6msg_m.h \
	util/hoinfo.h \
	util/logger.h \
	util/ssinfo.h
$O/ipv6/mip6.o: ipv6/mip6.cc \
	util/mih_m.h \
	ipv6/mip6.h \
	util/Portable.h \
	util/fsm.h \
	util/IPv6Addr.h \
	util/hoinfo.h \
	ipv6/ipv6msg_m.h \
	util/logger.h \
	util/ssinfo.h
$O/ipv6/ipv6msg_m.o: ipv6/ipv6msg_m.cc \
	util/Portable.h \
	util/IPv6Addr.h \
	ipv6/ipv6msg_m.h
$O/ipv6/dhcpv6.o: ipv6/dhcpv6.cc \
	util/mih_m.h \
	ipv6/dhcpv6.h \
	util/Portable.h \
	util/fsm.h \
	util/IPv6Addr.h \
	util/hoinfo.h \
	ipv6/ipv6msg_m.h \
	util/logger.h \
	util/ssinfo.h
$O/ipv6/ipv6node.o: ipv6/ipv6node.cc \
	ipv6/ipv6node.h \
	util/Portable.h \
	util/logger.h
$O/ipv6/ra.o: ipv6/ra.cc \
	util/mih_m.h \
	ipv6/ra.h \
	util/Portable.h \
	util/fsm.h \
	util/IPv6Addr.h \
	util/hoinfo.h \
	util/logger.h \
	ipv6/ipv6msg_m.h \
	util/ssinfo.h
$O/ipv6/Internet.o: ipv6/Internet.cc \
	util/Portable.h \
	util/IPv6Addr.h \
	ipv6/ipv6msg_m.h \
	util/logger.h \
	ipv6/Internet.h
$O/mobility/WiMaxBasicMobility.o: mobility/WiMaxBasicMobility.cc \
	mobility/WiMaxBasicMobility.h \
	$(INETMANET_PROJ)/src/base/INETDefs.h \
	$(INETMANET_PROJ)/src/linklayer/mfcore/AirFrame_m.h \
	$(INETMANET_PROJ)/src/base/Coord.h \
	$(INETMANET_PROJ)/src/base/INotifiable.h \
	$(INETMANET_PROJ)/src/base/ModuleAccess.h \
	$(INETMANET_PROJ)/src/base/NotifierConsts.h \
	$(INETMANET_PROJ)/src/world/ChannelControl.h \
	$(INETMANET_PROJ)/src/base/NotificationBoard.h \
	$(INETMANET_PROJ)/src/util/FWMath.h \
	$(INETMANET_PROJ)/src/base/BasicModule.h
$O/mobility/WiMaxLineSegmentsMobilityBase.o: mobility/WiMaxLineSegmentsMobilityBase.cc \
	mobility/WiMaxBasicMobility.h \
	$(INETMANET_PROJ)/src/linklayer/mfcore/AirFrame_m.h \
	$(INETMANET_PROJ)/src/base/INETDefs.h \
	$(INETMANET_PROJ)/src/base/Coord.h \
	$(INETMANET_PROJ)/src/base/INotifiable.h \
	$(INETMANET_PROJ)/src/base/ModuleAccess.h \
	$(INETMANET_PROJ)/src/base/NotifierConsts.h \
	$(INETMANET_PROJ)/src/base/NotificationBoard.h \
	$(INETMANET_PROJ)/src/world/ChannelControl.h \
	$(INETMANET_PROJ)/src/util/FWMath.h \
	$(INETMANET_PROJ)/src/base/BasicModule.h \
	mobility/WiMaxLineSegmentsMobilityBase.h
$O/mobility/WiMaxRandomWPMobility.o: mobility/WiMaxRandomWPMobility.cc \
	$(INETMANET_PROJ)/src/linklayer/mfcore/AirFrame_m.h \
	$(INETMANET_PROJ)/src/base/INETDefs.h \
	$(INETMANET_PROJ)/src/base/NotificationBoard.h \
	$(INETMANET_PROJ)/src/base/BasicModule.h \
	mobility/WiMaxBasicMobility.h \
	mobility/WiMaxRandomWPMobility.h \
	$(INETMANET_PROJ)/src/base/Coord.h \
	$(INETMANET_PROJ)/src/base/ModuleAccess.h \
	$(INETMANET_PROJ)/src/base/INotifiable.h \
	$(INETMANET_PROJ)/src/base/NotifierConsts.h \
	$(INETMANET_PROJ)/src/util/FWMath.h \
	$(INETMANET_PROJ)/src/world/ChannelControl.h \
	mobility/WiMaxLineSegmentsMobilityBase.h
$O/port-win32/addrpack.o: port-win32/addrpack.cc \
	util/Portable.h
$O/util/IPv6Addr.o: util/IPv6Addr.cc \
	util/Portable.h \
	util/IPv6Addr.h \
	util/logger.h
$O/util/ssinfo.o: util/ssinfo.cc \
	util/mih_m.h \
	util/Portable.h \
	util/IPv6Addr.h \
	util/hoinfo.h \
	util/logger.h \
	util/ssinfo.h
$O/util/mih_m.o: util/mih_m.cc \
	util/mih_m.h \
	util/Portable.h \
	util/IPv6Addr.h
$O/util/logger.o: util/logger.cc \
	util/logger.h
$O/util/fsm.o: util/fsm.cc \
	util/fsm.h \
	util/logger.h
$O/wimax/wmaxmsg_m.o: wimax/wmaxmsg_m.cc \
	wimax/wmaxmsg_m.h \
	util/Portable.h \
	util/IPv6Addr.h \
	wimax/wmaxmsg.h
$O/wimax/wmaxmaccs.o: wimax/wmaxmaccs.cc \
	wimax/wmaxmsg_m.h \
	$(INETMANET_PROJ)/src/linklayer/ethernet/EtherFrame_m.h \
	$(INETMANET_PROJ)/src/linklayer/contract/Ieee802Ctrl_m.h \
	wimax/wmaxmaccs.h \
	$(INETMANET_PROJ)/src/base/INETDefs.h \
	$(PON_PROJ)/src/common/CopyableQueueCVectors.h \
	util/hoinfo.h \
	wimax/wmaxmsg.h \
	wimax/wmaxmac.h \
	$(VLANS_PROJ)/src/linklayer/Ieee802VlanCtrl_m.h \
	util/Portable.h \
	util/fsm.h \
	$(INETMANET_PROJ)/src/networklayer/contract/IPAddress.h \
	util/IPv6Addr.h \
	$(INETMANET_PROJ)/src/networklayer/arp/ARPPacket_m.h \
	util/logger.h \
	wimax/wmaxctrl.h \
	ipv6/ipv6msg_m.h \
	util/ssinfo.h \
	$(INETMANET_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INETMANET_PROJ)/src/linklayer/ethernet/Ethernet.h
$O/wimax/wmaxctrl.o: wimax/wmaxctrl.cc \
	wimax/wmaxmsg_m.h \
	util/mih_m.h \
	$(INETMANET_PROJ)/src/linklayer/mfcore/AirFrame_m.h \
	$(INETMANET_PROJ)/src/base/INETDefs.h \
	$(PON_PROJ)/src/common/CopyableQueueCVectors.h \
	util/hoinfo.h \
	wimax/wmaxmsg.h \
	wimax/wmaxmac.h \
	$(PON_PROJ)/src/common/ServiceConfig.h \
	wimax/wmaxradio.h \
	util/Portable.h \
	util/fsm.h \
	$(INETMANET_PROJ)/src/base/Coord.h \
	$(INETMANET_PROJ)/src/base/ModuleAccess.h \
	util/IPv6Addr.h \
	wimax/wmaxctrl.h \
	util/logger.h \
	$(INETMANET_PROJ)/src/util/FWMath.h \
	util/ssinfo.h \
	$(INETMANET_PROJ)/src/world/ChannelControl.h
$O/wimax/wmaxphy.o: wimax/wmaxphy.cc \
	wimax/wmaxmsg_m.h \
	util/mih_m.h \
	wimax/wmaxphy.h \
	$(INETMANET_PROJ)/src/base/INETDefs.h \
	$(INETMANET_PROJ)/src/linklayer/mfcore/AirFrame_m.h \
	util/hoinfo.h \
	wimax/wmaxmsg.h \
	util/Portable.h \
	$(INETMANET_PROJ)/src/base/Coord.h \
	$(INETMANET_PROJ)/src/base/ModuleAccess.h \
	util/IPv6Addr.h \
	util/logger.h \
	$(INETMANET_PROJ)/src/util/FWMath.h \
	util/ssinfo.h \
	$(INETMANET_PROJ)/src/world/ChannelControl.h
$O/wimax/wmaxradio.o: wimax/wmaxradio.cc \
	wimax/wmaxmsg_m.h \
	$(INETMANET_PROJ)/src/base/INETDefs.h \
	$(INETMANET_PROJ)/src/linklayer/mfcore/AirFrame_m.h \
	$(PON_PROJ)/src/common/CopyableQueueCVectors.h \
	util/hoinfo.h \
	wimax/wmaxmsg.h \
	wimax/wmaxmac.h \
	wimax/wmaxradio.h \
	util/Portable.h \
	util/fsm.h \
	$(INETMANET_PROJ)/src/base/Coord.h \
	$(INETMANET_PROJ)/src/base/ModuleAccess.h \
	util/IPv6Addr.h \
	util/logger.h \
	$(INETMANET_PROJ)/src/util/FWMath.h \
	$(INETMANET_PROJ)/src/world/ChannelControl.h \
	util/ssinfo.h
$O/wimax/wmaxmac.o: wimax/wmaxmac.cc \
	wimax/wmaxmsg_m.h \
	$(INETMANET_PROJ)/src/base/INETDefs.h \
	$(PON_PROJ)/src/common/CopyableQueueCVectors.h \
	util/hoinfo.h \
	wimax/wmaxmac.h \
	wimax/wmaxmsg.h \
	$(PON_PROJ)/src/common/ServiceConfig.h \
	$(INETMANET_PROJ)/src/networklayer/common/InterfaceEntry.h \
	util/Portable.h \
	util/fsm.h \
	$(INETMANET_PROJ)/src/networklayer/common/IInterfaceTable.h \
	$(INETMANET_PROJ)/src/base/ModuleAccess.h \
	$(INETMANET_PROJ)/src/base/NotifierConsts.h \
	$(INETMANET_PROJ)/src/networklayer/common/InterfaceTableAccess.h \
	util/IPv6Addr.h \
	wimax/wmaxctrl.h \
	util/logger.h \
	util/ssinfo.h \
	$(INETMANET_PROJ)/src/linklayer/contract/MACAddress.h \
	$(INETMANET_PROJ)/src/networklayer/common/InterfaceToken.h

