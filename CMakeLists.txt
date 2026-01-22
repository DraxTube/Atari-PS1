cmake_minimum_required(VERSION 3.10)

# Percorso SDK
if(NOT DEFINED ENV{VITASDK})
    message(FATAL_ERROR "VITASDK non trovato. Controlla il workflow!")
endif()
set(VITASDK $ENV{VITASDK})

# Forza l'inclusione dei moduli PS Vita
list(APPEND CMAKE_MODULE_PATH "${VITASDK}/share/cmake/Modules")
include("${VITASDK}/share/vita.cmake" REQUIRED)

project(IPTVVita)

# Crediti DraxTube (GitHub: DraxTube | YT: @DraxTube01)
set(VITA_APP_NAME "IPTV Vita DraxTube")
set(VITA_TITLEID "DRAXT0001")

# Sorgenti
add_executable(IPTVVita src/main.c)

# Librerie necessarie per il networking e il video player
target_link_libraries(IPTVVita 
    SceNet_stub 
    SceNetCtl_stub 
    SceSsl_stub 
    SceHttp_stub
    SceVideoPlayer_stub
    SceDisplay_stub
    SceGxm_stub
    SceSysmodule_stub
    SceLibKernel_stub
    SceAppUtil_stub
)

# Creazione VPK
vita_setup_vpk(IPTVVita 
    ${VITA_TITLEID} 
    ${VITA_APP_NAME}
)
