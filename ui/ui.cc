#include "ui.hh"
#include "../globals.hh"
#include "../imgui/imgui.h"
#include "../imgui/imgui_internal.h"
inline int category = 1;
int i = 0;

void ui::render() {
    if (!globals.active) return;

    ImGui::SetNextWindowPos(ImVec2(window_pos.x, window_pos.y), ImGuiCond_Once);
    ImGui::SetNextWindowSize(ImVec2(window_size.x, window_size.y));
    ImGui::SetNextWindowBgAlpha(1.0f);

    ImGui::Begin(window_title, &globals.active, window_flags);
    {
        if (ImGui::Button("Afisare", { 120, 25 })) { category = 1; };
        ImGui::SameLine(); 
        if (ImGui::Button("Inserare", { 120, 25 })) { category = 2; };
        ImGui::SameLine(); 
        if (ImGui::Button("Debug", { -1, 25 })) { category = 3; };
        switch (category)
        {
            case 1: { // Afisare
                if (mainRegister->count() > 0)
                {
                    ImGui::Text("Your list(%d):", mainRegister->count());
                }
                if (mainRegister->returnHead() != 0)
                {
                    node* p = mainRegister->returnHead();
                    while (p != NULL)
                    {
                        ImGui::Text("---\nAlbum: %s\nArtist: %s\n---", p->album, p->artist);
                        p = p->next;
                        i++;
                    }
                }
                if (mainRegister->count() == 0)
                {
                    ImGui::Text("Your list is empty :(");
                }
                break;
            }
            case 2: { // Inserare
                ImGui::InputText("Album", globals.user_name, IM_ARRAYSIZE(globals.user_name));
                ImGui::InputText("Artist", globals.pass_word, IM_ARRAYSIZE(globals.pass_word));
                if (ImGui::Button("Add")) {
                    mainRegister->insert(globals.user_name, globals.pass_word);
                }
                break;
            }
            case 3: { // Debug
                ImGui::Text("Head Address: %p", mainRegister->returnHead());
                //ImGui::Text("Next Address: %x", mainRegister->returnHead()->next);
                if (ImGui::Button("Clear List")) { mainRegister->~node(); };
                if (mainRegister->returnHead() != 0)
                {
                    ImGui::Text("Pointers HEAD/NEXT:");
                    node* p = mainRegister->returnHead();
                    while (p != NULL)
                    {
                        ImGui::Text("---\nAlbum(addr): %x\nAlbum(text): %s\nArtist(addr): %x\nArtist(text): %s\nPointer addr: %x\n---", p->album, p->album, p->artist, p->artist, p);
                        p = p->next;
                    }
                }
                break;
            }
        }       
    }
    ImGui::End();
}

void ui::init(LPDIRECT3DDEVICE9 device) {
    dev = device;
	
    // colors
    ImGui::StyleColorsDark();

	if (window_pos.x == 0) {
		RECT screen_rect{};
		GetWindowRect(GetDesktopWindow(), &screen_rect);
		screen_res = ImVec2(float(screen_rect.right), float(screen_rect.bottom));
		window_pos = (screen_res - window_size) * 0.5f;

		// init images here
	}
}