local ability = Ability("Military_Ammo")

function ability:Init()
    Events.RegisterListener(self, "Attack.Land.Pre", function(event)
        if event.target and event.target ~= self:GetOwner() then
            return -- Attacker is someone else
        end

        if not self:IsToggled() then
            return -- Not Active
        end

        local owner = self:GetOwner()
        local requiredMana = self:GetManacost()
        if owner["CurrentMana"] < requiredMana then
            return -- Not Enough Mana
        end

        owner:ConsumeMana(requiredMana)
        --event.target:TakeDamage(self:GetValue("Damage"), self:GetValue("Damage_Type", "DamageType"), owner, self)
        event.damage = event.damage + self:GetValue("Damage")
    end)
end
