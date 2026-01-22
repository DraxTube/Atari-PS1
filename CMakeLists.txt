cmake_minimum_required(VERSION 3.10)
project(IPTVVita)

# Crediti DraxTube
set(VITA_APP_NAME "IPTV Vita DraxTube")
set(VITA_TITLEID "DRAXT0001")

# Percorso dei sorgenti
set(SOURCES src/main.c)

# Inizializza il Vita SDK
if(NOT DEFINED ENV{VITASDK})
    message(FATAL_ERROR "VITASDK non trovato!")
endif()

add_executable(IPTVVita ${SOURCES})

# Link alle librerie necessarie per IPTV (Networking e Video)
target_link_libraries(IPTVVita 
    SceNet_stub 
    SceNetCtl_stub 
    SceSsl_stub 
    SceHttp_stub
    SceVideoPlayer_stub
    SceDisplay_stub
    SceGxm_stub
    SceSysmodule_stub
)

# Crea il file VPK
vita_setup_vpk(IPTVVita 
    ${VITA_TITLEID} 
    ${VITA_APP_NAME}
    FILE sce_sys/icon0.png sce_sys/icon0.png
)
