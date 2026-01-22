cmake_minimum_required(VERSION 3.10)
project(IPTVVita)

# Crediti DraxTube (GitHub: DraxTube | YT: @DraxTube01)
set(VITA_APP_NAME "IPTV Vita DraxTube")
set(VITA_TITLEID "DRAXT0001")

# Percorso dei sorgenti
set(SOURCES src/main.c)

# Controlla se l'ambiente VITASDK esiste
if(NOT DEFINED ENV{VITASDK})
    message(FATAL_ERROR "Ambiente VITASDK non trovato!")
endif()

# QUESTA È LA RIGA CHE MANCAVA: Carica i comandi specifici per PS Vita
set(VITASDK $ENV{VITASDK})
include("${VITASDK}/share/vita.cmake")

add_executable(IPTVVita ${SOURCES})

# Librerie di sistema PS Vita
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
    SceCommonDialog_stub
    debugnet
)

# Ora questo comando funzionerà perché abbiamo incluso vita.cmake
vita_setup_vpk(IPTVVita 
    ${VITA_TITLEID} 
    ${VITA_APP_NAME}
)
