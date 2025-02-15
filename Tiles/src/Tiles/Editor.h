#include <vector>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Lumina/Layer.h"

#include "Lumina/Utils/Timer.h"
#include "Lumina/Utils/FileReader.h"

// Client
#include "Theme/ThemeManager.h"

#include "Panels/HeaderPanel.h"
#include "Panels/TextureSelectionPanel.h"
#include "Panels/TileViewportPanel.h"
#include "Panels/LayerSelectionPanel.h"
#include "Panels/ToolSelectionPanel.h"

#include "Core/ToolModes.h"
#include "Core/Layers.h"
#include "Core/Atlas.h"
#include "Core/State.h"
#include "Core/Base.h"

#include "spdlog/spdlog.h"

class Editor : public Lumina::Layer
{
public:
    virtual void OnUpdate(float timestep) override
    {
        float elapsedTime = m_FrameTimer.Elapsed();
        m_FPS = 1.0f / elapsedTime;
        m_FrameTimer.Reset();
    }

    virtual void OnUIRender() override
    {
        ImGui::Begin("FPS Counter");
        ImGui::Text("FPS: %.1f", m_FPS);
        ImGui::End();

        m_HeaderPanel.Render();
        m_TextureSelectionPanel.Render();
        m_TileViewportPanel.Render();
        m_ToolSelectionPanel.Render();
        m_LayerSelectionPanel.Render(); 
    }

    virtual void OnAttach() override
    {
        spdlog::info("Welcome to spdlog!");

        Tiles::ThemeManager::GetInstance().ApplyDarkTheme();

        // References
        m_Layers = Tiles::MakeShared<Tiles::Layers>();
        m_Layers->Resize(16, 16);

        m_Atlas = Tiles::MakeShared<Tiles::Atlas>();

        m_Modes = Tiles::MakeShared<Tiles::ToolModes>();

        m_State = Tiles::MakeShared<Tiles::State>();
        m_State->SetTileLayers(m_Layers);

        // Header
        m_HeaderPanel.SetTileLayers(m_Layers);
        m_HeaderPanel.SetTextureAtlas(m_Atlas);
        m_HeaderPanel.SetState(m_State);

        // Viewport
        m_TileViewportPanel.SetTileLayers(m_Layers);
        m_TileViewportPanel.SetTextureAtlas(m_Atlas);
        m_TileViewportPanel.SetToolModes(m_Modes);
		m_TileViewportPanel.SetState(m_State);

        // Texture Selection
        m_TextureSelectionPanel.SetTextureAtlas(m_Atlas);

        // Layer Selection
        m_LayerSelectionPanel.SetTileLayer(m_Layers);
        m_LayerSelectionPanel.SetState(m_State);

        // Tool Selection
        m_ToolSelectionPanel.SetToolModes(m_Modes);
    }

    virtual void OnDetach() override
    {
        
    }

private:
    Tiles::Shared<Tiles::Layers> m_Layers;
    Tiles::Shared<Tiles::Atlas> m_Atlas;
    Tiles::Shared<Tiles::ToolModes> m_Modes;
    Tiles::Shared<Tiles::State> m_State;

    // Panels
    Tiles::HeaderPanel m_HeaderPanel;
    Tiles::TextureSelectionPanel m_TextureSelectionPanel;
    Tiles::TileViewportPanel m_TileViewportPanel;
    Tiles::LayerSelectionPanel m_LayerSelectionPanel;
    Tiles::ToolSelectionPanel m_ToolSelectionPanel;

    // Util
    Lumina::Timer m_FrameTimer;
    float m_FPS = 0;
};