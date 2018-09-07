local item = Item("Frozen_Orb")

------------------------------------------------------------------------------------------------------------------------
function item:GetPassiveModifier()
    return "Frozen_Orb"
end

------------------------------------------------------------------------------------------------------------------------
function item:OnAttackLanded(event)
    local modifier = event.target:AddNewModifier("Frozen_Orb", self:GetOwner(), self)
    modifier.slow = self:GetValue("Slow")
    modifier.duration = self:GetValue("Slow_Duration") * event.target:GetStatusResistance()
end

------------------------------------------------------------------------------------------------------------------------

local modifier = Modifier("Frozen_Orb")

------------------------------------------------------------------------------------------------------------------------
function modifier:GetBonusStrength()
    return self:GetValue("Attributes_All")
end

function modifier:GetBonusAgility()
    return self:GetValue("Attributes_All")
end

function modifier:GetBonusIntelligence()
    return self:GetValue("Attributes_All")
end

function modifier:GetBonusCharisma()
    return self:GetValue("Attributes_All")
end

------------------------------------------------------------------------------------------------------------------------
function modifier:GetProjectileParticle()
    return "projectile/Frozen_Orb"
end

------------------------------------------------------------------------------------------------------------------------

local modifier_slow = Modifier("Frozen_Orb_slow")

------------------------------------------------------------------------------------------------------------------------
function modifier_slow:GetPercentageBonusMovementSpeed()
    return self.slow
end
